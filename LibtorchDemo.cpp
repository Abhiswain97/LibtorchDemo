#include <torch/torch.h>
#include <iostream>

int main()
{
	torch::Tensor x = torch::randn({5, 5});

	std::cout << "Checking for cuda avalability: " << std::endl;
	if (torch::cuda::is_available())
	{
		std::cout << "cuda is available" << std::endl;
	}
	else
	{
		std::cout << "cuda is not available" << std::endl;
	}

	std::cout << x.to(torch::kCUDA) << std::endl;
	std::cout << x.to(torch::kCPU) << std::endl;
}