#include <iostream>
#include <deque>
#include<fstream>
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> Qi(k);
    int i;
    for (i = 0; i < k; i++) 
    {
        while ((!Qi.empty()) && (arr[i] >= arr[Qi.back()]))
            Qi.pop_back();
        Qi.push_back(i);
    }
    for ( ; i < n; i++) {
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && (Qi.front() <= i - k))
            Qi.pop_front();
        while ((!Qi.empty()) && (arr[i] >= arr[Qi.back()]))
            Qi.pop_back();
        Qi.push_back(i);
    }
    cout << arr[Qi.front()] << endl;
}

int dequeue_stl(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
  	}
  	return 0;
}

void challenge()
{
    dequeue_stl();
}

int main(int argc, char ** argv)
{
    std::string fn;
    if(argc == 1){
        challenge();
    }
    else{
        fn = argv[1];
        std::ofstream out(fn+".output");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
        challenge();
        out.close();
    }
    return 0;
}