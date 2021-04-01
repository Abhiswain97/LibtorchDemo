// LibtorchDemo.cpp : Defines the entry point for the application.
//

#include "LibtorchDemo.h"

#include <torch/torch.h>

using namespace std;

int main()
{
	cout << torch::randn({3, 2});
	return 0;
}
