from txtTObf_utils import smallest_factors_with_adjustment

code = str(input("Enter text:"))

with open('output.bf', 'w') as file:
    for i in code:
        n = ord(i)
        factors, remainder = smallest_factors_with_adjustment(n)[:2], smallest_factors_with_adjustment(n)[2]

        file.write("+" * factors[0]) 
        file.write("[>")  
        file.write("+" * factors[1])  
        file.write("<-]>")  

        if remainder < 0:
            file.write("-" * abs(remainder))  
        elif remainder > 0:
            file.write("+" * remainder) 

        file.write(".[-]\n")
