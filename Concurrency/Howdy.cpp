//#include <iostream>
//#include <thread>
//#include <vector>
//
//using std::cout;
//using std::endl;
//
//void sayHello(unsigned id) {
//    cout << "Howdy" << endl;
//}
//
//int main() {
//    std::vector<std::thread> threads;
//    for (unsigned i = 0; i < 2; ++i) {
//        threads.emplace_back(sayHello, i);
//    }
//    for (auto& entry : threads) {
//        entry.join();
//    }
//
//    return 0;
//}
//
