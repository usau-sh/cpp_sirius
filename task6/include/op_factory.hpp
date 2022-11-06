#ifndef OP_FACTORY_HPP_
#define OP_FACTORY_HPP_

#include "operations.hpp"

#include <memory>
#include <vector>

class OperationFactory {
    class OperationFactoryImplementation;
    std::unique_ptr<const OperationFactoryImplementation> Impl;

  public:
    OperationFactory();
    ~OperationFactory();
    std::unique_ptr<operation> CreateObject(const std::string &name) const;
    std::vector<std::string> GetAvailableObjects() const;
};

#endif