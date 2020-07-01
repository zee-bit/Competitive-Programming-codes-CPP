// // #include <map>
// #include <iostream>
// // #include <stdio.h>
// using namespace std;

// int main()
// {
//  // map <int, int> hashMap;
//  // hashMap.insert(pair<int, int>(0,2));
//  // hashMap.insert(pair<int, int>(0,2));
//  // map<int, int>::iterator it;
//  // for(it=hashMap.begin();it!=hashMap.end();it++)
//  //  cout<<it->first<<" "<<it->second<<"\n";
//  // return 0;
//  // int a=1,b=1;
//  // if(a-- || b-- && ++a)
//  //  cout<<a<<" "<<b;
//  // else
//  //  cout<<b<<a;
//  // int a=3,b=4;
//  // // a>b?a=b:b=a;
//  // a-=b<5;
//  // printf("%d %d", a, b);
//  double ans=250001.0-0.05;
//  cout<<ans;
// }

// #include <stdio.h>
// int main() {
//  int a, b=1;
//  a=b++ + b++;
//  printf("%d, %d", a, b);
// }

// #include <iostream>
// #include <cmath>
// #include <string>
// #include <stack>
// #include <vector>
// using namespace std;

// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     long long t, n;
//     cin>>t;
//     while(t--) {
//         cin>>n;
//         long long ans=10;
//         vector<long long> dp(100);
//         dp[0]=2, dp[1]=8, dp[2]=34;
//         for(long long i=3; n>ans+dp[i-1]; i++) {
//             ans+=dp[i-1];
//             dp[i]=4*dp[i-1]+dp[i-2];
//         }
//         cout<<ans<<"\n";
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// //int largest(int a[], int l, int n) {
// //   if(n == l)
// //       return 0;
// //   return max(a[n], largest(a, l, n+1));
// //}
// int main() {
//  // int var=75, var2=56, num;
//  // num=sizeof(var) ? (var2>23?((var==75)?'A':0):0):0;
//  // printf("%d",num);

//  // return 0;
//  //int a[4]={2, 5, 8, 12};
//  string s = "abab";
//  int l = s.length();
//         char max = s[0];
//         vector<string> maxStr;
//         maxStr.push_back(s.substr(0));
//         for(int i = 1; i < l; i++) {
//             if(s[i] > max) {
//                 max = s[i];
//                 maxStr.clear();
//             }
//             else if(s[i] == max)
//                 maxStr.push_back(s.substr(i));
//         }
//         sort(maxStr.begin(), maxStr.end(), greater<string>());
//         for(int i=0; i<maxStr.size(); i++)
//          cout<<maxStr[i]<<"\n";


//  int n=s.length(),i=0,j=1,k=0;
//     while(j+k<n)
//     {
//         if(s[i+k]==s[j+k]) k++;
//         else if(s[i+k]<s[j+k]) i=j++,k=0;
//         else j+=k+1,k=0;
//     }
//     return s.substr(i);
// }
// #include <cstdio>
// using namespace std;

// int main()
// {
// // #ifndef ONLINE_JUDGE
// //     // for getting input from input.txt
// //     freopen("input.txt", "r", stdin);
// //     // for writing output to output.txt
// //     freopen("output.txt", "w", stdout);
// // #endif
//     int n, num1, num2, original, i, rev, count1 = 0, count2 = 0, sum = 0;
//     //printf("Enter the range\n");
//     scanf("%d %d", &num1, &num2);

//     for (n = num1; n <= num2; n++)
//     {
//         original = n;
//         count1 = 0;
//         for (i = 1; i <= n; i++)
//         {
//             if (n % i == 0)
//             {
//                 count1++;
//             }
//         }
//         if (count1 == 2)
//         {
//             while (n > 0)
//             {
//                 rev = n % 10;
//                 sum = sum * 10 + rev;
//                 n = n / 10;
//             }
//             n = original;
//             count2 = 0;
//             for (i = 1; i <= sum; i++)
//             {
//                 if (sum % i == 0)
//                 {
//                     count2++;
//                 }
//             }
//             if (count2 == 2)
//             {
//                 printf("%d ", original);
//                 count1 = 0;
//             }
//         }
//     }
//     return 0;
// }
#include <ctime>
#include <chrono>
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace std::chrono;

const int N = 2e5;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};

void insert_numbers(long long x) {
    clock_t begin = clock();
    unordered_map<long long, int, custom_hash> numbers;

    for (int i = 1; i <= N; i++)
        numbers[i * x] = i;

    long long sum = 0;

    for (auto &entry : numbers)
        sum += (entry.first / x) * entry.second;

    printf("x = %lld: %.3lf seconds, sum = %lld\n", x, (double) (clock() - begin) / CLOCKS_PER_SEC, sum);
}

int main() {
    insert_numbers(107897);
    insert_numbers(126271);
}













