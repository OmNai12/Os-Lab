#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>
using namespace std;

int main1()
{
    char path[] = {'/', 'p', 'r', 'o', 'c'};
    DIR *pt = opendir(path);
    struct dirent *readptr;
    while (readptr = readdir(pt))
    {
        cout << readptr->d_name << "\n";
    }
    return 0;
}

int main()
{
    char path[] = {'/', 'p', 'r', 'o', 'c'};
    DIR *pt = opendir(path);
    struct dirent *readptr;
    while (readptr = readdir(pt))
    {
        if (readptr->d_name[0] >= '0' && '9' >= readptr->d_name[0])
        {
            string str = "/proc";
            int i = 0;

            str.push_back('/');
            i = 0;

            while (readptr->d_name[i])
                str.push_back(readptr->d_name[i++]);
            str.append("/stat");

            int len = str.size();
            len += 1;

            char statPath[len];
            i = 0;
            for (auto val : str)
                statPath[i++] = val;

            statPath[len - 1] = '\0';

            FILE *ptr = fopen(statPath, "r");
            if (ptr == NULL)
            {
                cout << "abcc";
                return 0;
            }
            char data[600];
            fscanf(ptr, "%*s %s ", data);

            cout << readptr->d_name << " " << data << "\n";
        }
    }
    return 0;
}