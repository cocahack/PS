#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, a;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector<int> answers(n, 0);
	    vector<int> stocks(n, 0);
	    stack<int> s;
	     
	    for(int i=0; i<n; ++i) {
	        cin >> stocks[i];
	    }
	    
	    for(int i=0; i<n; ++i) {
	        int p = -1;
	        while(s.size()) {
	            if(stocks[i] >= stocks[s.top()]) {
	                s.pop();
	            } else {
	                break;
	            }
	        }
	        if(s.size()) {
	            p = s.top();
	        }
	        answers[i] = i - p;
	        s.push(i);
	    }

 	    for(int i=0; i<n; ++i){
 	        cout << answers[i] << " ";
 	    }
 	    cout << "\n";
	}
	return 0;
}

