
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

// 假设这是你的象棋程序初始化函数
void init_chess_engine() {
    std::cout << "Initializing chess engine..." << std::endl;
    // 比如：初始化棋盘、加载开局库、设置参数等
}

int main(int argc, char** argv) {
    // 1. 初始化
    init_chess_engine();

    // 2. 创建 doctest context
    doctest::Context context;

    // 3. 传入命令行参数
    context.applyCommandLine(argc, argv);

    // 4. 可以设置一些选项
    context.setOption("order-by", "name");  // 按测试名排序
    context.setOption("success", true);     // 显示成功的测试

    // 5. 运行测试
    int res = context.run();

    // 6. 测试结束后清理（如果需要）
    std::cout << "Cleaning up..." << std::endl;

    // 7. 如果 doctest 要求退出（例如 --exit）
    if (context.shouldExit()) {
        return res;
    }

    // 8. 你也可以在这里运行程序的其他逻辑（可选）
    // run_chess_game();

    return res;
}