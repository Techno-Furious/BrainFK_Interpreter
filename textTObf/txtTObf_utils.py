def smallest_factors_with_adjustment(n):
    def is_prime(number):
        if number < 2:
            return False
        for i in range(2, int(number**0.5) + 1):
            if number % i == 0:
                return False
        return True

    
    def smallest_factors(number):
        if number <= 1:
            return (1, number)
        smallest_pair = (1, number)
        for i in range(2, int(number**0.5) + 1):
            if number % i == 0:
                factor_pair = (i, number // i)
                if max(factor_pair) < max(smallest_pair):
                    smallest_pair = factor_pair
        return smallest_pair

    
    if is_prime(n):
        factors_plus = smallest_factors(n + 1)
        remainder_plus = n - (factors_plus[0] * factors_plus[1])  

        factors_minus = smallest_factors(n - 1)
        remainder_minus = n - (factors_minus[0] * factors_minus[1])  

        if max(factors_plus) < max(factors_minus):
            return (factors_plus[0], factors_plus[1], remainder_plus)
        else:
            return (factors_minus[0], factors_minus[1], remainder_minus)
    else:
        factors = smallest_factors(n)
        remainder = n - (factors[0] * factors[1])
        return (factors[0], factors[1], remainder)

# n = 111
# factors = smallest_factors_with_adjustment(n)[:3]

# print(f"Number: {n}")
# print(f"Factors: {factors[0]} x {factors[1]} + ({remainder})")
