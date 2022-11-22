#pragma once
#include <chrono>
class Timer {
public:
  Timer() {
    _start_time = _current_time = _last_delta_tick = std::chrono::system_clock::now();
    _delta_time = std::chrono::duration<float>(0);
  }
  // restarts the start time to now, which basically resets the elapsed time count
  void Restart() {
    _start_time = std::chrono::system_clock::now();
  }
  // returns the amount of time since the last call to this function
  float GetDeltaTime() {
    _current_time = std::chrono::system_clock::now();
    _delta_time = _current_time - _last_delta_tick;
    _last_delta_tick = _current_time;
    return _delta_time.count();
  }  
  // returns the amount of time since last Restart
  float GetElapsedTime() {
    _current_time = std::chrono::system_clock::now();
    std::chrono::duration<float> elapsed_time = _current_time - _start_time;
    return elapsed_time.count();
  }
private:
  std::chrono::system_clock::time_point _start_time, _current_time, _last_delta_tick;
  std::chrono::duration<float> _delta_time;
};
