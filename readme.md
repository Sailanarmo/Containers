# Containers Library

This library is open source and free for anyone to use. 

Inspired by a question on Reddit: https://www.reddit.com/r/cpp_questions/comments/b5tr0g/print_container_name/

Thanks to Francios Andrieux and Artyer on Stackoverflow for helping me with template overloading: https://stackoverflow.com/questions/55422966/how-to-have-variadic-templates-with-a-type-and-a-size

### UPDATE 1
This update removes all of the included libraries and macros and makes powerful uses of templates. This makes this program a lot more efficient as you no longer need to include all of the libraries in the standard template library. 

### UPDATE 2
I have changed the way you print out the containers. Instead of calling `print(myContainer);`, you can now simply do `std::cout << myContainer << std::endl;`.

### Requirements
You will need a compiler which supports `C++ 14` or higher.

### Usage

Simply include the header file,`containers.hpp`, located in the Lib folder. If you can, include the Lib folder into your project.

When you want to construct a new container you may do either of the two options:

```cpp
int main()
{
  container::Cont<std::vector<int>> myVector("myVector");
  auto myVector2 = container::make_cont<std::vector<int>>("myVector2");
}
```

You may treat `myVector` or `myVector2` as any normal `std::vector`, such as `myVector.push_back(4);` However, as of right now, you cannot bracket initialize a `Cont<std::vector<T>>` or assign another `std::vector<T>` to `Cont<std::vector<T>>`. This will be implemented in a future update.
