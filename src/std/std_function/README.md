
## head file
```c++
template< class InputIt, class T >
T accumulate( InputIt first, InputIt last, T init );

template< class InputIt, class T >
constexpr T accumulate( InputIt first, InputIt last, T init );

template< class InputIt, class T, class BinaryOperation>
T accumulate( InputIt first, InputIt last, T init,
              BinaryOperation op );

template< class InputIt, class T, class BinaryOperation >
constexpr T accumulate( InputIt first, InputIt last, T init,
                        BinaryOperation op );
```

# implementation:
```c++
template<class InputIt, class T, class BinaryOperation>
constexpr // since C++20
T accumulate(InputIt first, InputIt last, T init, 
             BinaryOperation op)
{
    for (; first != last; ++first) {
        init = op(std::move(init), *first); // std::move since C++20
    }
    return init;
}
```
