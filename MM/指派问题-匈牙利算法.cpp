#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

#define Max 17
int n;                    //ά�� 
int s[Max][Max];        //ԭʼ���� 
int p[Max][Max];        //��Լ���� 
int q[Max][Max];        //0:δ������ 1:����1�� 2: ����2��(����) 
int row[Max], col[Max];    //����0Ԫ�ظ��� 
int r[Max][Max];        //0:��0Ԫ�� 1:�Ƕ���0Ԫ�� 2:����0Ԫ�� 
int x[Max],y[Max];        //����ʱ�Ƿ񱻴򹴣�1��0���� 

//��ÿ��ÿ�е�0Ԫ�ظ��� 
void countZero()
{
    memset(row, 0, sizeof(row));
    
    memset(col, 0, sizeof(col));
    
    memset(r, 0, sizeof(r));
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (p[i][j] == 0)
                row[i]++, col[j]++;
        }
    }
}

//�����ٵ��߸�������0Ԫ�� 
int drawLine()
{    
    memset(q, 0, sizeof(q));
    
    for (int i = 0; i < n; ++i)
        x[i] = 1, y[i] = 0;
    
    //row �����в�������0Ԫ�ص��д򹴣� 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (r[i][j] == 2)
            {
                x[i] = 0;
                
                break;
            }
        }
    }
    
    bool is = 1;
    while (is)    //ѭ��ֱ��û�й����Դ� 
    {
        is = 0;
        //col �Դ򹴵����к�0Ԫ�ص�δ�򹴵��д� 
        for (int i = 0; i < n; ++i)
        {
            if (x[i] == 1)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (p[i][j] == 0 && y[j] == 0)
                    {
                        y[j] = 1;
                        
                        is = 1;
                    }
                }
            }
        }
        
        //row �Դ򹴵����к�����0Ԫ�ص�δ�򹴵��д� 
        for (int j = 0; j < n; ++j)
        {
            if (y[j] == 1)
            {
                for (int i = 0; i < n; ++i)
                {
                    if (p[i][j] == 0 && x[i] == 0 && r[i][j] == 2)
                    {
                        x[i] = 1;
                        
                        is = 1;
                    }
                }
            }
        }
    }
    
    //û�д򹴵��к��д򹴵��л��ߣ�����Ǹ�������0Ԫ�ص�����ֱ���� 
    int line = 0;
    for (int i = 0; i < n; ++i)
    {
        if (x[i] == 0)
        {
            for (int j = 0; j < n; ++j)
                q[i][j]++;
                
            line++;
        }
        
        if (y[i] == 1)
        {
            for (int j = 0; j < n; ++j)
                q[j][i]++;
                
            line++;
        }
    }
    
    return line;
}

//�Ҷ���0Ԫ�ظ��� 
/*1.�Һ�0���ٵ���һ��/��    2.���������¸���/��0Ԫ������λ�õ�row[],col[]
  3.ֱ������0�����ߣ����ﶨ��Ϊrow[]col[]ȫΪINT_MAX,��ʾ����/����0Ԫ��*/ 
int find()
{
    countZero();
    
    int zero = 0;     //����0Ԫ�صĸ��� 
    
    while (1)
    {
        //row[i] = INT_MAX��ʾ������0Ԫ�أ���ֹ��*min_element()��ͻ 
        for (int i = 0; i < n; ++i)
        {
            if (row[i] == 0)
                row[i] = INT_MAX;
            if (col[i] == 0)
                col[i] = INT_MAX;
        }
        
        bool stop = 1;
        
        if (*min_element(row, row+n) <= *min_element(col, col+n))    //������0Ԫ�� 
        {
            //�Һ�0���ٵ���һ�� 
            int tmp = INT_MAX, index = -1;
            for (int i = 0; i < n; ++i)
            {
                if (tmp > row[i])
                    tmp = row[i], index = i;
            }
            
            /*�Ҹ�������һ��û��������0Ԫ��(����0Ԫ��)���ҵ�һ������*/ 
            int index2 = -1;            //���ж���0Ԫ�ص���ֵ
            for (int i = 0; i < n; ++i)
                if (p[index][i] == 0 && col[i] != INT_MAX)
                {
                    index2 = i;
                    stop = 0;            //�ҵ�����0Ԫ�������ѭ�� 
                    zero++;                //����0Ԫ�صĸ��� 
                    break;
                }
            
            //�Ҳ�������0Ԫ���� 
            if (stop)    
                break;
                
            //��� 
            row[index] = col[index2] = INT_MAX;    
            r[index][index2] = 1;                //����0Ԫ�أ��ȵȻ�++. 
            
            //�������������е�col,row
            for (int i = 0; i < n; ++i)
                if (p[index][i] == 0 && col[i] != INT_MAX)    //�����л���0��û�������Ÿ��� 
                    col[i]--;
            for (int i = 0; i < n; ++i)
                if (p[i][index2] == 0 && row[i] != INT_MAX)
                    row[i]--;
        }
        else                                                        //������0Ԫ�� 
        {
            int tmp = INT_MAX, index = -1;
            for (int i = 0; i < n; ++i)
            {
                if (tmp > col[i])
                    tmp = col[i], index = i;
            }
        
            int index2 = -1;
            for (int i = 0; i < n; ++i)
                if (p[i][index] == 0 && row[i] != INT_MAX)
                {    
                    index2 = i;
                    stop = 0;
                    zero++;
                    break;
                }
                
            if (stop)
                break;
                
            row[index2] = col[index] = INT_MAX;
            r[index2][index] = 1;
            
            for (int i = 0; i < n; ++i)
                if (p[index2][i] == 0 && col[i] != INT_MAX)
                    col[i]--;
            for (int i = 0; i < n; ++i)
                if (p[i][index] == 0 && row[i] != INT_MAX)
                    row[i]--;
        }
    }
    //r[i][j] 0:��0Ԫ�� 1:�Ƕ���0Ԫ�� 2:����0Ԫ�� 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (p[i][j] == 0)
                r[i][j]++;
                
    return zero;
}

int main()
{
    int m;
    
    cin >> m;
    
    while (m--)
    {    
        cin >> n;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> s[i][j];
        
        //�й�Լ 
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                p[i][j] = *max_element(s[i], s[i]+n)-s[i][j];    //������ 
                //p[i][j] = s[i][j]-*min_element(s[i],s[i]+j);     //�����С 
        
        //�й�Լ 
        for (int j = 0; j < n; ++j)
        {
            int tmp = INT_MAX;
            for (int i = 0; i < n; ++i)
            {
                if (tmp > p[i][j])
                    tmp = p[i][j];
            }
            for (int i = 0; i < n; ++i)
                p[i][j] -= tmp;
        }
        
        while (find() < n)
        {
            drawLine();
            
            //��С��δ�����ߵ���
            int min = INT_MAX;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)    
                    if (q[i][j] == 0 && min > p[i][j])
                        min = p[i][j];
            
            //����δ�������ĺͽ��� 
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (q[i][j] == 0)
                        p[i][j] -= min;
                    else if (q[i][j] == 2)
                        p[i][j] += min;        
        }

        //��� 
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (r[i][j] == 2)
                    ans += s[i][j];
                    
        cout << ans << endl;
    }
}
