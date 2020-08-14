 /**
  * P145SUMA - https://www.spoj.com/PTIT/problems/P145SUMA
  * Code by @trhgquan - https://github.com/trhgquan
  */

 #include<stdio.h>
 #include<string.h>

 int main() {
 	int n; scanf("%d", &n);
 	char num[51]; scanf("%s", num);
 	int sum_first = 0; int sum_second = 0; int has_other = 0;
 	for (int i = 0; i < n / 2; ++i){
 		if (num[i] != '4' && num[i] != '7') {
 			has_other = 1; break;
 		} else sum_first += (num[i] - 48);
 	}
 	for (int i = n / 2; i < n; ++i) {
 		if (num[i] != '4' && num[i] != '7') {
 			has_other = 1; break;
 		} else sum_second += (num[i] - 48);
 	}

 	if (has_other || sum_first != sum_second)
 		printf("NO");
 	else
 		printf("YES");

 	return 0;
 }
