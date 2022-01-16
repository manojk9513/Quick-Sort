//Recursive quick sort technique
#include <iostream>
#include <vector>

using namespace std;

int partetion(vector<int>& v,int s,int e)
{
	cout<<"Partetion Function"<<endl;
	int pivot=v[s];
	int cnt=0;
	for(int i=s+1;i<=e;i++)
	{
		if(v[i]<=pivot)
		{
			cnt++;
		}
	}

	int pvtIndex=s+cnt;

	swap(v[pvtIndex],v[s]);
	int i=s,j=e;
	while(i<pvtIndex && j>pvtIndex)
	{
		while(v[i]<=pivot)
		{
			i++;
		}

		while(v[j]>pivot)
		{
			j--;
		}

		if(i<pvtIndex && j>pvtIndex)
		{
			swap(v[i++],v[j--]);
		}
	}
	return pvtIndex;
}

void quickSort(vector<int>& v,int s,int e){
	cout<<"Quick Sort Function"<<endl;
	if(s>=e){
		return;
	}

	int p=partetion(v,s,e);

	quickSort(v,s,p-1); //sort the left sub array

	quickSort(v,p+1,e); //sort the right sub array

}


int main(){
	vector<int> v={6,3,8,2,1};
	quickSort(v,0,v.size()-1);

	for(int i:v)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
