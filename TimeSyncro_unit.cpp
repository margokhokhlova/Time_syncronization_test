#include <iostream>
#include <ctime> //to get current time
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>         // std::this_thread::sleep_until
#include <dos.h>

using namespace std;

long timediff(clock_t t1, clock_t t2) {
	long elapsed;
	elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000; // for the moment in mS
														 //	cout << elapsed << endl;
	return elapsed;

}

void TimerSleep(long ms_sec) {
	//cout<<"Sleep for " << ms_sec << " ";
	Sleep(ms_sec);
}

// long operation to time
int fib(int n) {
	if (n < 2) {
		return n;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}
void op(int n) {
	100000 * 10;
}
int
  main (int argc, char** argv)
{

//timer 1 with Chrono
  cout << "Test one with Chrono high_resolution clock" <<endl<<"Simple run: "<< endl;
  auto start_time = std::chrono::high_resolution_clock::now();
  fib(12);
  auto end_time = std::chrono::high_resolution_clock::now();
  auto time = end_time - start_time;
  std::cout << "fib(100) took " <<
  std::chrono::duration_cast<std::chrono::microseconds>(time).count() << " to run.\n";
  cout << "Run and sleep for 30 ms" << endl;
  start_time = std::chrono::high_resolution_clock::now();
  fib(12);
  TimerSleep(30);
  end_time = std::chrono::high_resolution_clock::now();
  time = end_time - start_time;
  std::cout << "fib(100) and 30000 mks of sleep took " <<
  std::chrono::duration_cast<std::chrono::microseconds>(time).count() << " to run.\n";



//timer 2 with  DWORD
  DWORD interval = 30;	// 
  cout << "Test one with DWORD time frames" << endl << "Simple run: " << endl;
  DWORD startTime = GetTickCount();
  fib(12);
  DWORD endTime = GetTickCount();
  auto timeE = endTime - startTime;
  std::cout << "fib(100) took " <<
	  timeE << " to run.\n";

  cout << "Run and sleep for 30 ms" << endl;
  
  startTime = GetTickCount();
  fib(12);
  DWORD startTime2 = GetTickCount();
  while (GetTickCount() < (startTime2 + interval))
  {
	  //DO NOTHING JUST WAIT
  }
  endTime = GetTickCount();
  auto time2 = endTime - startTime;
  std::cout << "fib(100) and 30000 mks of sleep took "  <<
	  time2 << " to run.\n";

  //test 3 delay
  cout << "Test one with Sleep_for ms" << endl << "Simple run: " << endl;
  startTime = GetTickCount();
  fib(12);
  std::this_thread::sleep_for(30ms);
  endTime = GetTickCount();
  time2 = endTime - startTime;
  std::cout << "fib(12) and 30000 mks of sleep took " << 	  time2 << " to run.\n";

  // test
  cout << "Test one with _sleep ms" << endl << "Simple run: " << endl;
  std::chrono::high_resolution_clock::now();
  fib(12);
  _sleep(30); //
  end_time = std::chrono::high_resolution_clock::now();
  time = end_time - start_time;
  std::cout << "fib(100) and 30000 mks of sleep took " <<
	  std::chrono::duration_cast<std::chrono::microseconds>(time).count() << " to run.\n";



  //test 4 check this https://www.codemiles.com/c-c/implementing-synchronization-in-c-with-threads-t2753.html
  typedef void* HANDLE;
  HANDLE myHandleToSomething = op;
//https://www.codemiles.com/c-c/implementing-synchronization-in-c-with-threads-t2753.html
  WaitForSingleObject(myHandleToSomething, 5);

  return (0);
}



