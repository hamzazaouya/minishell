#ifndef TOKEN_H
#define TOKEN_H
typedef struct token_struct
{
    enum
    {
        TOKEN_INF,
        TOKEN_HERDOC,
        TOKEN_OUTF,
        TOKEN_APPEND,
        TOKEN_WORD,
        TOKEN_PIPE,
        TOKEN_END,
    } type;
    char *value;
} t_token;

t_token *init_token(int type, char *value);

#endif