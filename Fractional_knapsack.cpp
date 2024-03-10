#include <bits/stdc++.h>

using namespace std;

//first is profit second is weight
typedef pair<double, double> item;

//return if first item has greater value by weight ratio than the 
bool comp_item(item& a, item& b)
{
    return a.first/a.second > b.first/b.second;
}

double fractional_knapsack(item items[], int n, double capacity)
{
    double profit= 0;

    //sort items by their value/weight ratio in decreasing order
    sort(items, items+n, comp_item);
    
    for(int i= 0; i<n; i++)
    {
        if(items[i].second <= capacity)
        {
            capacity -= items[i].second;
            profit += items[i].first;
        }
        else
        {
            profit += items[i].first/items[i].second * capacity;
            capacity= 0;
            break;
        }
    }
    
    return profit;
}

int main(void)
{
    
    int n;
    item items[100];
    double capacity;

    cout<<"Enter the number of items\n";
    cin>>n;

    cout<<"Enter the total capacity of knapsack\n";
    cin>>capacity;

    cout<<"Enter the profit and weight for "<< n <<" items\n";
    for(int i= 0; i<n; i++)
    {
        cin>>items[i].first>>items[i].second;
    }
    
    cout<< "The maximum profit is = "<< fractional_knapsack(items, n, capacity) <<endl;
    
    return 0;
}