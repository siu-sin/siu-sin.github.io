#include <print>
#include "Logger.h"
#include "CarFactory.h"

using namespace std;

int main() {
	ToyotaFactory myFactory;
	auto myCar {myFactory.requestCar()};
	println("{}", myCar->info());
	        Logger::setLogFilename("log.out");
	std::println("Hueta?");
    return 0;
}
