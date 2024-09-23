#include "Expr.hpp"
#include "ExprVisitor.hpp"
#include "Token.hpp"

IExpr::IExpr(std::unique_ptr<IExpr> left, std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right) :
    m_left(std::move(left)), m_op(std::move(op)), m_right(std::move(right))
{
}

IExpr::IExpr() :
    m_left(nullptr), m_op(nullptr), m_right(nullptr)
{
}

IExpr::~IExpr()
{
}

Binary::Binary(std::unique_ptr<IExpr> left, std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right) :
    IExpr(std::move(left), std::move(op), std::move(right))
{
}

Binary::~Binary()
{
}



Grouping::Grouping(std::unique_ptr<IExpr> expr) :
    IExpr(std::move(expr), nullptr, nullptr)
{
}

Grouping::~Grouping()
{
}

Literal::Literal(std::unique_ptr<IToken> literal) :
    IExpr(nullptr, std::move(literal), nullptr)
{
}

Literal::~Literal()
{
}

Unary::Unary(std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right) :
    IExpr(nullptr, std::move(op), std::move(right))
{
}

Unary::~Unary()
{
}
