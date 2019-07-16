#include <stdio.h>
using namespace std;

int main() {
	int three, five, n; scanf("%d", &n);
	five = n/5, n%=5;
	while(five>=0){
		if(!(n%3)){
			three = n/3;
			n%=3;
			break;
		}
		five--;
		n+=5;
	}
	printf("%d", n == 0 ? five + three : -1);
	return 0;
}
