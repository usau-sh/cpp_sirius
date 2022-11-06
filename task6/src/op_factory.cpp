#include "op_factory.hpp"

#include <map>
#include <string>

class OperationFactory::OperationFactoryImplementation {
    class IOperationCreator {
      public:
        virtual ~IOperationCreator(){};
        virtual std::unique_ptr<operation> Create() const = 0;
    };
    using OperationCreatorPtr = std::shared_ptr<IOperationCreator>;
    std::map<std::string, OperationCreatorPtr> RegisteredCreators;

  public:
    template <typename cur_obj_t>
    class OperationCreator : public IOperationCreator {
        std::unique_ptr<operation> Create() const override {
            return std::make_unique<cur_obj_t>();
        }
    };

    OperationFactoryImplementation() { RegisterAll(); }

    template <typename T> void RegisterCreator(const std::string &name) {
        RegisteredCreators[name] = std::make_shared<OperationCreator<T>>();
    }

    void RegisterAll() {
        RegisterCreator<add>("+");
        RegisterCreator<subtract>("-");
        RegisterCreator<multiply>("*");
        RegisterCreator<derivative>("der");
        RegisterCreator<integral>("int");
    }

    std::unique_ptr<operation> CreateObject(const std::string &name) const {
        auto creator = RegisteredCreators.find(name);
        if (creator == RegisteredCreators.end()) {
            throw;
        }
        return creator->second->Create();
    }

    std::vector<std::string> GetAvailableObjects() const {
        std::vector<std::string> result;
        for (const auto &creatorPair : RegisteredCreators) {
            result.push_back(creatorPair.first);
        }
        return result;
    }
};

std::unique_ptr<operation>
OperationFactory::CreateObject(const std::string &name) const {
    return Impl->CreateObject(name);
}

std::vector<std::string> OperationFactory::GetAvailableObjects() const {
    return Impl->GetAvailableObjects();
}

OperationFactory::OperationFactory()
    : Impl(std::make_unique<
           OperationFactory::OperationFactoryImplementation>()) {}

OperationFactory::~OperationFactory(){};