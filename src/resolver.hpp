#ifndef CPPPARSER_RESOLVER_HPP
#define CPPPARSER_RESOLVER_HPP
#include <memory>

namespace cppParser {

class Factory;
template <typename Interface>
std::shared_ptr<Interface> ResolveAndCreate(std::shared_ptr<Factory> factory);

/**
 * Wrapper class to prevent this function from being inlined
 * @tparam Interface
 */
template <typename Interface>
class Resolver {
   public:
    virtual std::shared_ptr<Interface> Create(std::shared_ptr<Factory> factory) {
        return ResolveAndCreate<Interface>(factory);
    }
};
}


#endif  // CPPPARSER_RESOLVER_HPP
