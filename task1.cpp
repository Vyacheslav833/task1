#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void arr_output(short* arr, short size);
void push_back(short*& arr, short& size, string value);
double percentile_90(short* arr, short size);
double median(short* arr, short size); 
short max_value(short* arr, short size);
short min_value(short* arr, short size);
double average_value(short* arr, short size);


int main(int argc, char* argv[])
{
	ifstream f;
	string value;
	short size = 0;
	short* arr = new short[size];

	for (int i = 0; i < argc; i++) {
		if (i == 1)	{
			f.open(argv[i]);
			if (f.is_open()){ 
				while (getline(f, value)) { push_back(arr, size, value); }
				cout << fixed;
				cout.precision(2);
				arr_output(arr, size);
				cout << "\n";
				cout << percentile_90(arr, size) << endl;
				cout << median(arr, size) << endl;
				cout << max_value(arr, size) << endl;;
				cout << min_value(arr, size) << endl;;
				cout << average_value(arr, size) << endl;
				f.close();
			}
		}
	}
	delete[]arr;
	system("pause");
	return 0;
}

void push_back(short*& arr, short& size, string value) //„H„p„„€„|„~„u„~„y„u „t„y„~„p„}„y„‰„u„ƒ„{„€„s„€ „}„p„ƒ„ƒ„y„r„p „y„x „†„p„z„|„p
{
	short* new_arr = new short[size + 1];
	for (short i = 0; i < size; i++) { new_arr[i] = arr[i]; }
	new_arr[size] = stoi(value);
	size++;
	delete[]arr;
	arr = new_arr;
}

double percentile_90(short* arr, short size) //90 „„u„‚„ˆ„u„~„„„y„|„Ž
{
	double N;
	double fract;

	for (short i = 0; i < size; i++)
	{
		for (short j = 0; j < size; j++)
		{
			if (arr[i]<arr[j])
			{
				short x;
				x = arr[i];
				arr[i] = arr[j];
				arr[j] = x;
			}
		}
	}
	N = 90 * (double)(size - 1) / 100 + 1;
	fract = (double)(N - ((90 * (size - 1) / 100) + 1));
	return (double)(arr[(short)(N-1)]+fract*(double)(arr[(short)(N)]-arr[(short)(N - 1)]));
}

double median(short* arr, short size) //„M„u„t„y„p„~„p
{
	if (size % 2 == 0)
	{
		return (double)((arr[size / 2] + arr[size / 2 + 1]) / 2);
	}
	else
	{
		return arr[(size / 2)+1];
	}
}

short max_value(short* arr, short size) //„M„p„{„ƒ„y„}„p„|„Ž„~„€„u „x„~„p„‰„u„~„y„u
{
	short max = arr[0];
	for (short i = 0; i < size; i++)
	{
		if (max < arr[i]) { max = arr[i]; }
	}
	return max;
}

short min_value(short* arr, short size) //„M„y„~„y„}„p„|„Ž„~„€„u „x„~„p„‰„u„~„y„u
{
	short min = arr[0];
	for (short i = 0; i < size; i++)
	{
		if (min > arr[i]) { min = arr[i]; }
	}
	return min;
}

double average_value(short* arr, short size) //„R„‚„u„t„~„u„u „x„~„p„‰„u„~„y„u
{
	double aver_value=0;
	for (short i = 0; i < size; i++) { aver_value = aver_value + arr[i]; }
	return aver_value / (double)size;
}

void arr_output(short* arr, short size)  //„B„„r„€„t „}„p„ƒ„ƒ„y„r„p
{
	for (short i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}