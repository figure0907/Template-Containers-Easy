#pragma once

template<typename Container, typename BeginFn, typename EndFn>
class IterableWrapper {
public:
    using value_type = typename std::remove_cvref_t<
        decltype(*std::declval<BeginFn>()(std::declval<Container>()))
    >;

    IterableWrapper(const Container& container, BeginFn begin_fn, EndFn end_fn)
        : container_(container), begin_fn_(begin_fn), end_fn_(end_fn) {}

    auto begin() const { return begin_fn_(container_); }
    auto end() const { return end_fn_(container_); }

private:
    const Container& container_;
    BeginFn begin_fn_;
    EndFn end_fn_;
};

template<typename Container, typename BeginFn, typename EndFn>
auto make_iterable_wrapper(const Container& container, BeginFn begin_fn, EndFn end_fn) {
    return IterableWrapper<Container, BeginFn, EndFn>(container, begin_fn, end_fn);
}
