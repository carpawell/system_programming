#include <string>


class UserId {
public:
    UserId() : name_(), id_() {}
    UserId(std::string name, size_t id) : name_(std::move(name)), id_(id) {}

    UserId(const UserId& other) = default;
    UserId(UserId&& other) noexcept : name_(std::move(other.name_)), id_(other.id_) {}

    UserId& operator=(const UserId& other) noexcept {
        if (this == &other)
            return *this;
        name_ = other.name_;
        id_ = other.id_;
        return *this;
    }
    UserId& operator=(UserId&& other) noexcept {
        if (this == &other)
            return *this;
        name_ = std::move(other.name_);
        id_ = other.id_;
        return *this;
    }

    bool operator<(const UserId& other) {
        return id_ < other.id();
    }
    bool operator==(const UserId& other) {
        return id_ == other.id();
    }
    bool operator>(const UserId& other) {
        return id_ > other.id();
    }

    std::string name() const { return name_; }
    size_t id() const { return id_; }
private:
    std::string name_;
    size_t id_;
};


namespace std {
    template<class T> struct hash;
    template <>
    struct hash<UserId> {
        size_t operator()(UserId user) const {
            return hash<string>()(user.name()) ^ hash<size_t >()(user.id());
        }
    };
}

