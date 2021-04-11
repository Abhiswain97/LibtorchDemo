#include <torch/torch.h>
#include <iostream>

int main()
{
	torch::Tensor x = torch::randn({5, 5});

	std::cout << "Checking for cuda avalability: " << std::endl;

	float progress = 0.0;
	while (progress <= 1.0)
	{
		int barWidth = 70;

		std::cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i <= barWidth; ++i)
		{
			if (i < pos)
				std::cout << "=";
			else if (i == pos)
				std::cout << ">";
			else
				std::cout << " ";
		}
		std::cout << "] " << int(progress * 100.0) << " %\r";
		std::cout.flush();

		progress += 0.01; // for demonstration only
	}
	std::cout << std::endl;

	if (torch::cuda::is_available())
	{
		std::cout << "cuda is available!" << std::endl;
		std::cout << x.to(at::kCUDA) << std::endl;
		std::cout << x.to(at::kCPU) << std::endl;
	}
	else
	{
		std::cout << "cuda is not available" << std::endl;
		std::cout << x.to(at::kCPU) << std::endl;
	}
}
