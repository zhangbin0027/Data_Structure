        //
//  BubbleSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

//冒泡
void BubbleSort(int R[], int n)
{
    for (int i = n; i >= 1; --i)
    {
        int isChanged = 0;
        for (int j = 1; j < i; ++j)
        {
            if (R[j-1] > R[j])
            {
                int temp = R[j];
                R[j] = R[j-1];
                R[j-1] = temp;
                isChanged = 1;
            }
        }
        if (isChanged == 0) {
            return;
        }
    }
}
