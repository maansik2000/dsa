#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Item {
    int value, weight;
    
    Item(int value, int weight)
    {
       this->value=value;
       this->weight=weight;
    }
};

bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

//Fractional Knapsack problem using greedy
double fractional_Knapsack(int w, struct Item arr[], int n){
    sort(arr, arr + n, cmp);

    int curweight = 0; //current weight in knapsack
    double finalValue = 0.0;

    //looping through all the item
    for(int i=0;i<n;i++){
        //check weight of the item while adding into the bag
        if(curweight + arr[i].weight <= w){
            curweight += arr[i].weight;
            finalValue += arr[i].value;
        }else {
			int remain = w - curweight;
			finalValue += arr[i].value*((double)remain/ (double)arr[i].weight);
			break;
		}
    }

    return finalValue;
}


int main(){
    int W = 50; // Weight of knapsack
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Maximum value we can obtain = "
		<< fractional_Knapsack(W, arr, n);
	return 0;

}