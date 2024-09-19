import matplotlib
matplotlib.use("TkAgg")
from matplotlib import pyplot as plt
import numpy as np
import tkinter as tk
from tkinter import ttk
import cv2
import glob

##from matplotlib import pyplot as plt

def fun1_1(): ## Histogram Equalization
     img = cv2.imread("images/plant.jpg")
     cv2.imshow("1-1", img) #oringinal img
     img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY) #轉灰階
     #plt.figure()
     plt.title('Histogram for gray scale picture')
     plt.xlabel("gray value")
     plt.ylabel("pixel number")
     plt.xlim([0, 256])
     #hist= cv2.calcHist([img], [0], None, [256], [0.0,255.0])  
     hist, bins, patches= plt.hist(img.ravel(),256,[0,256])
     x = int(input("enter a number"))
     print(hist[x])
     plt.show()
     cv2.waitKey(0)
     cv2.destroyAllWindows()
     pass

def fun1_2(): ## Histogram Equalization
    img = cv2.imread("images/plant.jpg",cv2.IMREAD_GRAYSCALE)
    equ = cv2.equalizeHist(img)
    cv2.imshow("1-2", equ) #show equalized img
    plt.figure()
    plt.title('Histogram for equalized image')
    plt.xlabel("gray value")
    plt.ylabel("pixel number")
    plt.xlim([0, 256])
    plt.hist(equ.ravel(),256,[0,256])
    plt.show()
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    pass

## Hough Circle Transform and Histogram
def fun2_1(): ## Hough circle transform
    img = cv2.imread("images/q2_train.jpg")
    grayimg = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    grayimg = cv2.medianBlur(grayimg,7) #前處理

    circles = cv2.HoughCircles(grayimg,cv2.HOUGH_GRADIENT,1.4,10,param1=50,param2=30,minRadius=13,maxRadius=20)

    circles = np.uint16(np.around(circles))

    for i in circles[0,:]:
        # draw the outer circle
        cv2.circle(img,(i[0],i[1]),i[2],(0,255,0),2)
        # draw the center of the circle
        cv2.circle(img,(i[0],i[1]),2,(0,0,255),3)
    
    cv2.imshow("2-1",img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    pass


def fun2_2(): ## Hue histogram
    img = cv2.imread("images/q2_train.jpg")
    grayimg = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    grayimg = cv2.medianBlur(grayimg,7)

    circles = cv2.HoughCircles(grayimg,cv2.HOUGH_GRADIENT,1.4,10,param1=50,param2=30,minRadius=13,maxRadius=20)
    circles = np.uint16(np.around(circles))

    circle = np.zeros(img.shape[0:2], dtype = "uint8") #黑底圖
    for i in circles[0,:]:
      cv2.circle(circle,(i[0],i[1]),i[2],255,-1) #在circle底圖上用houghcircle的結果畫白色圓
      

    mask = circle
    
    masked = cv2.bitwise_and(img, img, mask=mask) #與原圖做mask 把原圖的點點抓出來
    #cv2.imshow('s',masked)
    hsvimg = cv2.cvtColor(masked,cv2.COLOR_BGR2HSV)
   
    hsvimg_h,hsvimg_s,hsvimg_v = cv2.split(hsvimg) #分離出h domain
    
    dot = hsvimg_h.ravel()
    weights = np.ones_like(dot)/2290 #未normalized前區間[100,130]發現最大值為2290，故之後權重除以2290使得最大值為1(normalized)
    plt.hist(dot,30,[100,130],weights=weights)
    plt.xlim([0,180])
    plt.title('Normalized hue histogram')
    plt.xlabel("Angle")
    plt.ylabel("Probability")
    plt.show()
    pass


def fun2_3(): ## Back projection
     img = cv2.imread('images/q2_test.jpg')
     imghsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
     dothsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
     # calculating object histogram
     dothist = cv2.calcHist([dothsv],[0,1],None,[2,2],[107,116,100,190])
     # normalize histogram and apply backprojection
     cv2.normalize(dothist,dothist,0,255,cv2.NORM_MINMAX)
     imgback = cv2.calcBackProject([imghsv],[0,1],dothist,[107,116,100,190],1)
     # convolute with circular disc
     disc = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(5,5))
     cv2.filter2D(imgback,-1,disc,imgback)
     # threshold and binary AND
     ret,imgback = cv2.threshold(imgback,50,255,cv2.THRESH_BINARY)

     cv2.imwrite('images/result.jpg',imgback)
     cv2.imshow('reslut',imgback)
     pass

## Camera Calibration
def fun3_1(): ## Corner detection
    # termination criteria
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
     
    # prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    objp = np.zeros((8*11,3), np.float32)
    objp[:,:2] = np.mgrid[0:11,0:8].T.reshape(-1,2)
    
    # Arrays to store object points and image points from all the images.
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane.
    
    images = glob.glob('images/CameraCalibration/*.bmp')
    
    for fname in images:
        img = cv2.imread(fname)
        gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
        # Find the chess board corners
        ret, corners = cv2.findChessboardCorners(gray, (11,8),None)
    
        # If found, add object points, image points (after refining them)
        if ret == True:
             objpoints.append(objp)
             corners2 = cv2.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
             imgpoints.append(corners2)
    
             # Draw and display the corners
             cv2.drawChessboardCorners(img, (11,8), corners2,ret)
             cv2.namedWindow('img',cv2.WINDOW_NORMAL) #調整一下視窗大小(那不然太大了ＱＱ)
             cv2.imshow('img',img)
             print("請按任意鍵顯示下一張")
             cv2.waitKey(0)
    
    cv2.destroyAllWindows()
    pass


def fun3_2(): ## Find the intrinsic matrix
    # termination criteria
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
     
    # prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    objp = np.zeros((8*11,3), np.float32)
    objp[:,:2] = np.mgrid[0:11,0:8].T.reshape(-1,2)
    
    # Arrays to store object points and image points from all the images.
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane.
    
    images = glob.glob('images/CameraCalibration/*.bmp')
    
    for fname in images:
     img = cv2.imread(fname)
     gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
        # Find the chess board corners
     ret, corners = cv2.findChessboardCorners(gray, (11,8),None)
    
        # If found, add object points, image points (after refining them)
     if ret == True:
         objpoints.append(objp)
         corners2 = cv2.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
         imgpoints.append(corners2)
    
    ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1],None,None)
    print("intrinsic matrix")
    print(mtx)
    pass


def fun3_3(): ## Find the extrinsic matrix
    # termination criteria
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
     
    # prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    objp = np.zeros((8*11,3), np.float32)
    objp[:,:2] = np.mgrid[0:11,0:8].T.reshape(-1,2)
    
    # Arrays to store object points and image points from all the images.
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane.
    
    value = numberChosen.get() #從combobox讀值
    if value == '1':
         img = cv2.imread("images/CameraCalibration/1.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '2':
         img = cv2.imread("images/CameraCalibration/2.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '3':
         img = cv2.imread("images/CameraCalibration/3.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '4':
         img = cv2.imread("images/CameraCalibration/4.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '5':
         img = cv2.imread("images/CameraCalibration/5.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '6':
         img = cv2.imread("images/CameraCalibration/6.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '7':
         img = cv2.imread("images/CameraCalibration/7.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '8':
         img = cv2.imread("images/CameraCalibration/8.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '9':
         img = cv2.imread("images/CameraCalibration/9.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '10':
         img = cv2.imread("images/CameraCalibration/10.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '11':
         img = cv2.imread("images/CameraCalibration/11.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '12':
         img = cv2.imread("images/CameraCalibration/12.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '13':
         img = cv2.imread("images/CameraCalibration/13.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '14':
         img = cv2.imread("images/CameraCalibration/14.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    if value == '15':
         img = cv2.imread("images/CameraCalibration/15.bmp")
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
    # Find the chess board corners
    ret, corners = cv2.findChessboardCorners(gray, (11,8),None)
    
    # If found, add object points, image points (after refining them)
    if ret == True:
         objpoints.append(objp)
         corners2 = cv2.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
         imgpoints.append(corners2)

    ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1],None,None)
    rvecs = cv2.Rodrigues(rvecs[0])
    extrinsic_matrix = cv2.hconcat([rvecs[0], tvecs[0]])
    print("extrinsic matrix")
    print(extrinsic_matrix)
    pass


def fun3_4(): ## Find the distortion matrix
    # termination criteria
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
     
    # prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    objp = np.zeros((8*11,3), np.float32)
    objp[:,:2] = np.mgrid[0:11,0:8].T.reshape(-1,2)
    
    # Arrays to store object points and image points from all the images.
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane.
    
    images = glob.glob('images/CameraCalibration/*.bmp')
    
    for fname in images:
        img = cv2.imread(fname)
        gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
        # Find the chess board corners
        ret, corners = cv2.findChessboardCorners(gray, (11,8),None)
    
        # If found, add object points, image points (after refining them)
        if ret == True:
             objpoints.append(objp)
             corners2 = cv2.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
             imgpoints.append(corners2)
    
    ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1],None,None)
    print("distortion matrix")
    print(dist) 
    pass



def fun4_1(): ## Augmented Reality
    axis = np.float32([[2,2,-2], [2,0,-2], [0,0,-2], [0,2,-2], [2,2,0],[2,0,0],[0,0,0],[0,2,0]])
    # termination criteria
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
     
    # prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    objp = np.zeros((8*11,3), np.float32)
    objp[:,:2] = np.mgrid[0:11,0:8].T.reshape(-1,2)
    
    # Arrays to store object points and image points from all the images.
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane.
    
    images = glob.glob('images/CameraCalibration/*.bmp')
    
    for fname in images:
        img = cv2.imread(fname)
        gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
        # Find the chess board corners
        ret, corners = cv2.findChessboardCorners(gray, (11,8),None)
    
        # If found, add object points, image points (after refining them)
        if ret == True:
             objpoints.append(objp)
             corners2 = cv2.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
             imgpoints.append(corners2)
    
    ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1],None,None)

    images = ['images/CameraCalibration/1.bmp','images/CameraCalibration/2.bmp','images/CameraCalibration/3.bmp','images/CameraCalibration/4.bmp','images/CameraCalibration/5.bmp']
    for fname in images:
         img = cv2.imread(fname)
         gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
         ret, corners = cv2.findChessboardCorners(gray, (11,8),None)
         if ret == True:
             corners2 = cv2.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
            
             ret,rvecs, tvecs = cv2.solvePnP(objp, corners2, mtx, dist)
             
             imgpts, jac = cv2.projectPoints(axis, rvecs, tvecs, mtx, dist)
             img = draw(img,corners2,imgpts)
             cv2.namedWindow('img',cv2.WINDOW_NORMAL)
             cv2.imshow('img',img)
             cv2.waitKey(500) #好像會有點lag所以雖然設定0.5秒但好像不太準QQ
     
    cv2.destroyAllWindows()
    pass

def draw(img, corners, imgpts):
    imgpts = np.int32(imgpts).reshape(-1,2)
    
    img = cv2.drawContours(img, [imgpts[:4]],-1,(0,0,255),3)
    
    for i,j in zip(range(4),range(4,8)):
        img = cv2.line(img, tuple(imgpts[i]), tuple(imgpts[j]),(0,0,255),3)
   
    img = cv2.drawContours(img, [imgpts[4:]],-1,(0,0,255),3)
    return img
    

main_window = tk.Tk()
main_window.geometry('1080x720')
main_window.title('HW2')

# all frames
left_frame = tk.Frame(main_window)
left_frame.place(relwidth=0.3, relheight=1)
middle_frame = tk.Frame(main_window)
middle_frame.place(relx=0.3, relwidth=0.3, relheight=1)
middle33 = tk.LabelFrame(middle_frame, text='3.3 Extrinsic matrix', font=("Helvetica", 15))
middle33.grid(row=3, column=2, columnspan=5, sticky='nsew', padx=5, ipadx=5, ipady=10)
middle33.place(relx=0, rely=0.3, relwidth=1, relheight=0.3)
right_frame = tk.Frame(main_window)
right_frame.place(relx=0.6, relwidth=0.3, relheight=1)

# all labels
l1 = tk.Label(left_frame, text='1. Histogram Equalization', font=("Helvetica", 15))
l1.grid(row=0, sticky='w', padx=5, pady=30)
l2 = tk.Label(left_frame, text='2. Hough Circle Transform and Histogram', font=("Helvetica", 15))
l2.grid(row=3, sticky='w', padx=5, pady=30)
l3 = tk.Label(middle_frame, text='3. Camera Calibration', font=("Helvetica", 15))
l3.grid(row=0, sticky='w', padx=5, pady=30)
l4 = tk.Label(right_frame, text='4. Augmented Reality', font=("Helvetica", 15))
l4.grid(row=0, sticky='w', padx=5, pady=30)
l_combolist = tk.Label(middle33, text='Select image:    ', font=("Helvetica", 15))
l_combolist.grid(row=1, column=0, sticky='nsew', pady=10)
l_combolist.place(relx=0.05, rely=0.1)

# all buttons
b11 = tk.Button(left_frame, text='Original Image Histogram ', font=("Helvetica", 18), width = 20, command=fun1_1)
b11.grid(row=1, sticky='nsew', padx=20, pady=20)
b12 = tk.Button(left_frame, text='Equalized Image Histogram ', font=("Helvetica", 18), width = 20, command=fun1_2)
b12.grid(row=2, sticky='nsew', padx=20, pady=20)
b21 = tk.Button(left_frame, text='Hough circle ', font=("Helvetica", 18), width = 20, command=fun2_1)
b21.grid(row=4, sticky='nsew', padx=20, pady=20)
b22 = tk.Button(left_frame, text='Hue histogram ', font=("Helvetica", 18), width = 20, command=fun2_2)
b22.grid(row=5, sticky='nsew', padx=20, pady=20)
b23 = tk.Button(left_frame, text='Back projection ', font=("Helvetica", 18), width = 20, command=fun2_3)
b23.grid(row=6, sticky='nsew', padx=20, pady=20)
b31 = tk.Button(middle_frame, text='Corner detection ', font=("Helvetica", 18), width = 20, command=fun3_1)
b31.grid(row=1, sticky='nsew', padx=50, pady=20)
b32 = tk.Button(middle_frame, text='Intrinsic matrix ', font=("Helvetica", 18), width = 20, command=fun3_2)
b32.grid(row=2, sticky='nsew', padx=50, pady=20)
b33 = tk.Button(middle33, text='Extrinsic matrix ', font=("Helvetica", 18), width = 25, command=fun3_3)
b33.grid(row=2, sticky='nsew', padx=50, pady=20)
b33.place(relx=0.05, rely=0.5)
b34 = tk.Button(middle_frame, text='Distortion matrix ', font=("Helvetica", 18), width = 25, command=fun3_4)
b34.grid(row=4, sticky='nsew', padx=50, pady=20)
b34.place(relx=0, rely=0.65)
b41 = tk.Button(right_frame, text='Augmented Reality ', font=("Helvetica", 18), width = 20, command=fun4_1)
b41.grid(row=1, sticky='nsew', padx=50, pady=20)

number = tk.StringVar()
numberChosen = ttk.Combobox(middle33, width=12, textvariable=number)
numberChosen['values'] = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
numberChosen.grid(row=1)
numberChosen.current(0)
numberChosen.place(relx=0.5, rely=0.1)

main_window.mainloop()



