#include <torch/torch.h>
#include <typeinfo>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

torch::Tensor Flatten(torch::Tensor x)
{
    return x.view({x.sizes()[0], -1});
}

struct Net : torch::nn::Module
{
    Net()
        : conv1(torch::nn::Conv2dOptions(1, 6, 3)),
          conv2(torch::nn::Conv2dOptions(6, 16, 3)),
          fc1(576, 120),
          fc2(120, 84), fc3(84, 10)
    {
        register_module("conv1", conv1);
        register_module("conv2", conv2);
        register_module("fc1", fc1);
        register_module("fc2", fc2);
        register_module("fc3", fc3);
    }

    torch::Tensor forward(torch::Tensor x)
    {
        x = torch::max_pool2d(torch::relu(conv1->forward(x)), 2);
        x = torch::max_pool2d(torch::relu(conv2->forward(x)), 2);
        x = Flatten(x);
        x = torch::relu(fc1->forward(x));
        x = torch::relu(fc2->forward(x));
        x = fc3->forward(x);
        return x;
    }

    torch::nn::Conv2d conv1;
    torch::nn::Conv2d conv2;
    torch::nn::Linear fc1;
    torch::nn::Linear fc2;
    torch::nn::Linear fc3;
};

Net model;

template <typename DataLoader>
void train(
    Net &model,
    DataLoader &data_loader)
{
    model.train();
    size_t batch_idx = 0;
    for (const auto &batch : data_loader)
    {
        auto data = batch.data;
        auto targets = batch.target;

        // std::cout << data.sizes();
        // optimizer.zero_grad();
        auto output = model.forward(data);

        std::cout << output;
        // auto loss = torch::nll_loss(output, targets);
        // AT_ASSERT(!std::isnan(loss.template item<float>()));
        // loss.backward();
        // optimizer.step();

        // if (batch_idx++ % kLogInterval == 0)
        // {
        //     std::printf(
        //         "\rTrain Epoch: %ld [%5ld/%5ld] Loss: %.4f",
        //         epoch,
        //         batch_idx * batch.data.size(0),
        //         dataset_size,
        //         loss.template item<float>());
        // }
    }
}

auto main() -> int
{
    Net model;

    torch::Tensor ip = torch::randn({1, 1, 28, 28});
    auto output = model.forward(ip);

    std::cout << output << std::endl;

    auto train_dataset = torch::data::datasets::MNIST("/home/abhishek/Desktop/LibtorchDemo/data").map(torch::data::transforms::Stack<>());
    auto example = train_dataset.get_batch(0);
    // std::cout << example.data.size(0) << std::endl;

    auto train_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
        std::move(train_dataset), 4);

    // train(model, *train_loader);
}
