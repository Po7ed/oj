#include <stdio.h>
#include <stdlib.h>

int main() {
  // For Windows
  // 对拍时不开文件输入输出
  // 当然，这段程序也可以改写成批处理的形式
  while (true) {
    system("shuju > test.in");  // 数据生成器将生成数据写入输入文件
    system("baoli.exe < test.in > baoli.out");  // 获取程序1输出
    system("T1.exe < test.in > T1.out");  // 获取程序2输出
    if (system("fc a.out b.out")) {
      // 该行语句比对输入输出
      // fc返回0时表示输出一致，否则表示有不同处
      system("pause>nul");  // 方便查看不同处
    //   return 0;
      // 该输入数据已经存放在test.in文件中，可以直接利用进行调试
    }
  }
}
