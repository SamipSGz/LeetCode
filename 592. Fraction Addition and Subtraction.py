class Solution:
    def fractionAddition(self, expression: str) -> str:
        from fractions import Fraction
        import re

        tokens = re.findall(r'[+-]?\d+/\d+', expression)
        
        result = Fraction(0, 1)
        
        for token in tokens:
            current_fraction = Fraction(token)
            result += current_fraction
        
        return f"{result.numerator}/{result.denominator}"