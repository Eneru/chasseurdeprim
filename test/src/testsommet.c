#include "testsommet.h"

Sommet a;

int init_suiteSommet(void)
{
    return 0;
}

int clean_suiteSommet(void)
{
    free(a);

    return 0;
}

void test_sommet_egalSom(void)
{
    CU_ASSERT(egalSom("abcde", "abcde") == VRAI);
    CU_ASSERT(egalSom("abcde", "abcd") == FAUX);
    CU_ASSERT(egalSom("abcde", "abcdr") == FAUX);
    CU_ASSERT(egalSom("abcde", "azert") == FAUX);
}

void test_sommet_copieSommet(void)
{
    a = copieSommet("abcde");
    CU_ASSERT(egalSom(a, "abcde") == VRAI);
    CU_ASSERT(egalSom(a, "abcdf") == FAUX);
}

int add_testsommets(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Sommet", init_suiteSommet, clean_suiteSommet);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "test_egalSom", test_sommet_egalSom) == NULL
        || CU_add_test(pSuite, "Test copieSommet", test_sommet_copieSommet) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
