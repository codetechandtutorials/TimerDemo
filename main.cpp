#include <iostream>
#include <iomanip>
#include "timer.h"
int main() {
  std::cout << "hello, timer.\n";
  Timer our_timer;
  while(our_timer.GetElapsedTime() < 1.f) {
    std::cout << std::fixed << std::setprecision(7) << std::setfill('0') << our_timer.GetElapsedTime() << '\n';
  }
  
  float timeout = 3.f;
  bool running = true;
  our_timer.Restart();
  while (running) {
    static int elapsed_counts = 0;  
    if (our_timer.GetElapsedTime() > timeout) {
      std::cout << "3 seconds elapsed";
      our_timer.Restart();
      elapsed_counts++;
      std::cout << "  count " << elapsed_counts << '\n';
    }
    if (elapsed_counts > 3) {
      running = false;
    }
  }

  return 0;
}
