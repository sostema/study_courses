import argparse
import math


def diffPayment(m, principal, interest, periods):
    return math.ceil(principal / periods + interest * (principal - (principal * (m - 1) / periods)))


def annualPayment(principal, interest, periods):
    return math.ceil(principal * (interest * (1 + interest) ** periods / ((1 + interest) ** periods - 1)))


def parseArguments(parser):
    if not parser.type or len(vars(parser)) < 5:
        print("Incorrect parameters")
    else:
        operation_type = parser.type
        if operation_type == "diff":
            if parser.payment:
                print("Incorrect parameters")
            else:
                if parser.principal and parser.periods and parser.interest:
                    principal = int(parser.principal)
                    periods = int(parser.periods)
                    interest = float(parser.interest) / 1200
                    if principal <= 0 or periods <= 0 or interest < 0:
                        print("Incorrect parameters")
                    else:
                        all_payment = 0
                        for m in range(1, periods + 1):
                            payment = diffPayment(m, principal, interest, periods)
                            all_payment += payment
                            print(f"Month {m}: paid out {payment}")
                        print()
                        print(f"Overpayment = {all_payment - principal}")
                else:
                    print("Incorrect parameters")
        elif operation_type == "annuity":
            if not parser.interest:
                print("Incorrect parameters")
            else:
                if not parser.periods:
                    principal = int(parser.principal)
                    payment = float(parser.payment)
                    interest = float(parser.interest) / 1200
                    periods = math.ceil(math.log(payment / (payment - interest * principal), 1 + interest))
                    years = periods // 12
                    months = periods % 12
                    if months == 0:
                        if years == 1:
                            print(f"You need 1 year to repay this credit!")
                        else:
                            print(f"You need {years} years to repay this credit!")
                    elif years == 0:
                        if months == 1:
                            print(f"You need 1 month to repay this credit!")
                        else:
                            print(f"You need {months} months to repay this credit!")
                    else:
                        if months == 1 and years == 1:
                            print(f"You need 1 year and 1 month to repay this credit!")
                        elif months == 1 and years != 1:
                            print(f"You need {years} years and 1 month to repay this credit!")
                        elif months != 1 and years == 1:
                            print(f"You need 1 year and {months} months to repay this credit!")
                        else:
                            print(f"You need {years} years and {months} months to repay this credit!")
                    print(f"Overpayment = {periods * payment - principal}")
                elif not parser.payment:
                    principal = int(parser.principal)
                    periods = float(parser.periods)
                    interest = float(parser.interest) / 1200
                    payment = math.ceil(
                        principal * (interest * (1 + interest) ** periods / ((1 + interest) ** periods - 1)))
                    print(f"Your annuity payment = {payment}!")
                    print(f"Overpayment = {periods * payment - principal}")
                elif not parser.principal:
                    payment = float(parser.payment)
                    periods = float(parser.periods)
                    interest = float(parser.interest) / 1200
                    principal = payment / (
                            interest * math.pow(1 + interest, periods) / (math.pow(1 + interest, periods) - 1))
                    print(f"Your credit principal = {principal}!")
                    print(f"Overpayment = {periods * payment - principal}")
        else:
            print("Incorrect parameters")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--type')
    parser.add_argument('--payment')
    parser.add_argument('--principal')
    parser.add_argument('--periods')
    parser.add_argument('--interest')
    parser = parser.parse_args()
    parseArguments(parser)
