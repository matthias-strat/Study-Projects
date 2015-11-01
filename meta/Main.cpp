#include <type_traits>

namespace MPL
{
    namespace Impl
    {
        // Compile-time list of types
        template <typename... Ts>
        struct TypeList
        {
            // Size of the list
            static constexpr std::size_t size{ sizeof...(Ts) };
        };

        // Count base case: 0.
        template <typename T, typename TTypeList>
        struct CountHelper : std::integral_constant<std::size_t, 0>
        {
        };
    
        // Interface type alias.
        template <typename T, typename TTypeList>
        using Count = CountHelper<T, TTypeList>;

        // Count recursive case.
        template <typename T, typename T0, typename... Ts>
        struct CountHelper<T, TypeList<T0, Ts...>>
            : std::integral_constant<std::size_t,
                (std::is_same<T, T0>::value ? 1 : 0) +
                    Count<T, TypeList<Ts...>>::value>
        {
        };

        // Alias for `Count > 0`.
        template <typename T, typename TTypeList>
        using Contains = std::integral_constant < bool, (Count<T, TTypeList>::value > 0) > ;

        template <typename TTypeList>
        struct UniqueHelper : std::true_type
        {
        };

        template <typename T, typename... Ts>
        struct UniqueHelper<TypeList<T, Ts...>>
        : std::integral_constant<bool, (Count<T, TypeList<T, Ts...>>::value <= 1 && UniqueHelper<TypeList<Ts...>>::value)>
        {
        };

        template <typename... Ts>
        using Unique = UniqueHelper<TypeList<Ts...>>;
	
        template <typename TCheckTypeList, typename TTypeList>
        struct ContainsAllHelper;


        template <typename TCheckTypeList, typename TTypeList>
        using ContainsAll = typename ContainsAllHelper<TCheckTypeList, TTypeList>::type;

        template <typename T, typename... TRest, typename TTypeList>
        struct ContainsAllHelper<TypeList<T, TRest...>, TTypeList>
            : std::integral_constant<bool, Contains<T, TTypeList>::value && ContainsAll<TypeList<TRest...>, TTypeList>::value>
        {
        };

        template <typename TTypeList>
        struct ContainsAllHelper<TypeList<>, TTypeList> : std::true_type
        {
        };
    }

    using Impl::TypeList;
    using Impl::Contains;
    using Impl::ContainsAll;
    using Impl::Count;
    using Impl::Unique;
}


int main()
{
    // MPL tests
    static_assert(MPL::ContainsAll<MPL::TypeList<int>, MPL::TypeList<int, float, char>>::value, "");
    static_assert(MPL::ContainsAll<MPL::TypeList<int, float>, MPL::TypeList<int, float, char>>::value, "");
    static_assert(MPL::ContainsAll<MPL::TypeList<int, float, char>, MPL::TypeList<int, float, char>>::value, "");

    // Count tests
    static_assert(MPL::Count<int, MPL::TypeList<int>>::value == 1, "");
    static_assert(MPL::Count<int, MPL::TypeList<>>::value == 0, "");
    static_assert(MPL::Count<int, MPL::TypeList<int, float, int>>::value == 2, "");

    // Unique tests
    static_assert(MPL::Unique<>::value, "");
    static_assert(MPL::Unique<int>::value, "");
    static_assert(MPL::Unique<int, float>::value, "");
    static_assert(!MPL::Unique<int, int>::value, "");
    static_assert(!MPL::Unique<float, float, int, double>::value, "");

    return 0;
}