//
// Created by Justice Bole on 8/30/22.
//

#ifndef CLASSTEMPLATE_TRIAD_H
#define CLASSTEMPLATE_TRIAD_H

template <typename T>
struct Triad
{
    T one{0};
    T two{0};
    T three{0};
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

#endif //CLASSTEMPLATE_TRIAD_H
