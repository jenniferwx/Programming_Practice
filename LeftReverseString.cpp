/*
定义字符串左旋转操作:把字符串前面的若干个字符移动到字符串尾部,如把字符串 abcdef 左旋转 2 位得到字符串 cdefab。
请实现字符串左旋转的函数,要求对长度为 n 的字符串操作的时间复杂度为 O(n),空间复杂度为 O(1)。
*/

void reverse(char *s,int from,int to)
{
    while (from < to)
    {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void leftshift(char *s,int n,int m)
{
    m %= n;           
    reverse(s, 0, m - 1); 
    reverse(s, m, n - 1);
    reverse(s, 0, n - 1); 
}
