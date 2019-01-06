
#ifndef SIMPLE_PTR_HPP_
#define SIMPLE_PTR_HPP_

#include "BaseComponent.hpp"

class SimplePtr
{
    public:
        explicit SimplePtr(BaseComponent *rawPtr);
        ~SimplePtr();
        BaseComponent *get() const;

    private:
        // Make the class non copyable
        SimplePtr(SimplePtr const &) = delete;
        SimplePtr &operator=(SimplePtr const &) = delete;

        BaseComponent *_rawPtr;
};

#endif // SIMPLE_PTR_HPP_
