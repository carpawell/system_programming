#include <vector>
#include <cstdlib>
#include "MergeSort.h"

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;



int main() {
    std::vector<long> yGraphicMultiThreading, yGraphicConsistent, xGraphics;

    for (int size = 10; size < 10000000; size *= 10) {

        std::vector<int> vector(size);

        for (int i = 0; i < size; i++) {
            vector[i] = rand();
        }

        xGraphics.push_back(size);
        yGraphicMultiThreading.push_back(merge_sort_in_threads(vector));
        yGraphicConsistent.push_back(merge_sort_consistent(vector));
    }

    plt::named_plot("Multithreading", xGraphics, yGraphicMultiThreading);
    plt::named_plot("Consistent", xGraphics, yGraphicConsistent );
    plt::xlabel("Number of elements");
    plt::ylabel("Time(ms)");
    plt::legend();
    plt::show();

    return 0;
}
