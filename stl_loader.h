// stl_loader.h
#include<vector>

#ifdef __CINT__
#pragma link C++ class vector<vector<double> >;
#pragma link C++ class vector<vector<float> >;
#pragma link C++ class vector<vector<int> >;
#else
template class std::vector<std::vector<double> >;
template class std::vector<std::vector<float> >;
template class std::vector<std::vector<int> >;
#endif
