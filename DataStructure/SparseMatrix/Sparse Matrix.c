SparseMatrix SparseMatrix::FastTranspose()
{//Return the transpose of (*this) in O(terms+cols)time
   SparseMatrix b(cols,rows,terms); //capacity of b.smArray is terms
   if(terms>0)
     {  //nonzero matrix
        int *rowSize = new int[cols]; //建一個陣列註記每一個原始sparse matrix的col裡面，有幾個row是有非零值的
        int *rowStart = new int[cols]; //建一個陣列註記原始sparse matrix col 轉置後變成新的sparse matrix row 後要從哪一個 b(新sparse matrix) 的index 開始寫起
        //compute rowSize[i] = number of terms in row i of b
        fill(rowSize,rowSize + cols,0); //initialize
        for(i=0;i<terms;i++) rowSize[smArray[i].col]++ //固定矩陣的每個 col，計算該 col 有多少非 0 值；
                                                       //由於稀疏矩陣記法已經撇除登記 0 值，所以計算每條 a.col 出現的次數，即可得到該矩陣各 col 所擁有的非 0 值。

        // rowStart[i] = starting position of row i in b
        rowStart[0] = 0;
        for(i=0;i<cols;i++) rowStart[i] = rowStart[i-1] + rowSize[i-1]; //註記每一條矩陣 col 個別要寫到哪一個 b 的 data row 位置
        // 每一個rowStart都是由上一個rowStart+上一次所加總的a.col出現非0值元素的個數

        for(i=0;i<terms;i++) //取出目前這個 a.col 應該寫在 b 的哪一條 data row，然後進行轉置寫入
        {// copy from *this to b
            int j = rowStart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        }// end of for
        delete [] rowSize;
        delete [] rowStart;
     }// end of if(terms>0)  
     return b;
}