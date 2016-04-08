#include <iostream>
#include <math.h>

using namespace std;

int countElement;
int countNotSortElement;
int heap[50];

int LEFTChild(int node)
{
    return 2 * node +1;
}

int RIGHTChild(int node)
{
    return 2 * node +2;
}

int Parent (int node)
{
    return floor(abs((node - 1)) / 2);
}

void SiftingDown(int node)
{
	int leftValue  = 0;
	int rightValue = 0;

	if (heap[node] < heap[LEFTChild(node)] && LEFTChild(node) < countNotSortElement)
	{
		leftValue = heap[LEFTChild(node)];
	}

	if (heap[node] < heap[RIGHTChild(node)] && RIGHTChild(node) < countNotSortElement)
	{
		rightValue = heap[RIGHTChild(node)];
	}

	if (leftValue > rightValue)
	{
		int tempValue = heap[node];
        heap[node] = heap[LEFTChild(node)];
        heap[LEFTChild(node)] = tempValue;

        int tempnode = LEFTChild(node);
		node = tempnode;

        SiftingDown(node);
	}
	else if (rightValue > leftValue)
	{
		int tempValue = heap[node];
        heap[node] = heap[RIGHTChild(node)];
        heap[RIGHTChild(node)] = tempValue;

        int tempnode = RIGHTChild(node);
		node = tempnode;

        SiftingDown(node);
	}
}

void HeapSort()
{
    countNotSortElement = countElement;
	
    while (true)
    {
        if (countNotSortElement > 1)
        {
			--countNotSortElement;

            int tempValue = heap[0];
            heap[0] = heap[countNotSortElement];
            heap[countNotSortElement] = tempValue;

            if (heap[0] >= heap[LEFTChild(0)] && heap[0] >= heap[RIGHTChild(0)])
            {
                continue;
            }

            SiftingDown(0);
        }
        else
        {
            break;
        }
    }

        for (int i(0); i < countElement; i++)
        {
            cout << heap[i] << "|" << endl;
        }

}

void SiftingUp(int node)
{
	if (heap[node] > heap[Parent(node)])
	{
		int tempValue = heap[node];
		heap[node] = heap[Parent(node)];
		heap[Parent(node)] = tempValue;

		if (Parent(node) != 0)
		{
			int tempNode = Parent(node);
			SiftingUp(tempNode);
		}
	}
}

void BuildHeap()
{
	//int heapSort[countElement];

    for (int i(0); i < countElement; i++)
    {
        heap[i] = rand () % 20 + 1;
		if (i != 0)
		{
			SiftingUp(i);
		}
        cout << heap[i] << "|" << endl;
    }

    for (int i(0); i < countElement; i++)
    {
        if (i == 0 || heap[Parent(i)] >= heap[i])
        {
            continue;
        }

        if (heap[Parent(i) < heap[i]])
        {
            int tempValue = heap[Parent(i)];
            heap[Parent(i)] = heap[i];
            heap[i] = tempValue;
            --i;
        }
    }

	for (int i(0); i < countElement; i++)
	{
		cout << heap[i] << endl;
	}

}

int main()
{
    cout << "enter count element in heap:";
    cin >> countElement;

    BuildHeap();
    HeapSort();

	system("pause");
    return 0;
}
