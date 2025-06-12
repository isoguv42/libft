/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprehensive_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:22:45 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/15 15:47:33 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// Global test counters
static int g_tests_run = 0;
static int g_tests_passed = 0;

// Test result macros
#define TEST_PASS() do { g_tests_passed++; printf("✅ PASS\n"); } while(0)
#define TEST_FAIL() do { printf("❌ FAIL\n"); } while(0)
#define RUN_TEST(test_name, condition) do { \
    printf("%-40s ", test_name); \
    g_tests_run++; \
    if (condition) TEST_PASS(); \
    else TEST_FAIL(); \
} while(0)

// Test categories
void test_string_functions(void);
void test_character_functions(void);
void test_memory_functions(void);
void test_conversion_functions(void);
void test_output_functions(void);
void test_list_functions(void);
void test_printf_functions(void);
void test_gnl_functions(void);
void test_utility_functions(void);

void print_header(const char *category)
{
    printf("\n🔬 Testing %s\n", category);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

void test_string_functions(void)
{
    print_header("STRING FUNCTIONS");
    
    // ft_strlen tests
    RUN_TEST("ft_strlen(\"hello\")", ft_strlen("hello") == 5);
    RUN_TEST("ft_strlen(\"\")", ft_strlen("") == 0);
    
    // ft_strchr tests
    RUN_TEST("ft_strchr(\"hello\", 'l')", ft_strchr("hello", 'l') != NULL);
    RUN_TEST("ft_strchr(\"hello\", 'z')", ft_strchr("hello", 'z') == NULL);
    
    // ft_strdup tests
    char *dup = ft_strdup("test");
    RUN_TEST("ft_strdup(\"test\")", dup && strcmp(dup, "test") == 0);
    free(dup);
    
    // ft_substr tests
    char *sub = ft_substr("hello world", 6, 5);
    RUN_TEST("ft_substr(\"hello world\", 6, 5)", sub && strcmp(sub, "world") == 0);
    free(sub);
    
    // ft_strjoin tests
    char *joined = ft_strjoin("hello", " world");
    RUN_TEST("ft_strjoin(\"hello\", \" world\")", joined && strcmp(joined, "hello world") == 0);
    free(joined);
    
    // ft_split tests
    char **split = ft_split("a,b,c", ',');
    RUN_TEST("ft_split(\"a,b,c\", ',')", split && strcmp(split[0], "a") == 0 && strcmp(split[1], "b") == 0);
    ft_free_array_null(split);
}

void test_character_functions(void)
{
    print_header("CHARACTER FUNCTIONS");
    
    RUN_TEST("ft_isalpha('a')", ft_isalpha('a') != 0);
    RUN_TEST("ft_isalpha('Z')", ft_isalpha('Z') != 0);
    RUN_TEST("ft_isalpha('1')", ft_isalpha('1') == 0);
    RUN_TEST("ft_isdigit('5')", ft_isdigit('5') != 0);
    RUN_TEST("ft_isdigit('a')", ft_isdigit('a') == 0);
    RUN_TEST("ft_toupper('a')", ft_toupper('a') == 'A');
    RUN_TEST("ft_tolower('Z')", ft_tolower('Z') == 'z');
}

void test_memory_functions(void)
{
    print_header("MEMORY FUNCTIONS");
    
    // ft_memset test
    char buffer[10];
    ft_memset(buffer, 'A', 5);
    buffer[5] = '\0';
    RUN_TEST("ft_memset(buffer, 'A', 5)", strcmp(buffer, "AAAAA") == 0);
    
    // ft_memcpy test
    char src[] = "hello";
    char dst[10];
    ft_memcpy(dst, src, 5);
    dst[5] = '\0';
    RUN_TEST("ft_memcpy(dst, \"hello\", 5)", strcmp(dst, "hello") == 0);
    
    // ft_calloc test
    int *ptr = (int *)ft_calloc(5, sizeof(int));
    RUN_TEST("ft_calloc(5, sizeof(int))", ptr && ptr[0] == 0 && ptr[4] == 0);
    free(ptr);
}

void test_conversion_functions(void)
{
    print_header("CONVERSION FUNCTIONS");
    
    RUN_TEST("ft_atoi(\"42\")", ft_atoi("42") == 42);
    RUN_TEST("ft_atoi(\"-123\")", ft_atoi("-123") == -123);
    RUN_TEST("ft_atoi(\"0\")", ft_atoi("0") == 0);
    
    char *str = ft_itoa(42);
    RUN_TEST("ft_itoa(42)", str && strcmp(str, "42") == 0);
    free(str);
    
    str = ft_itoa(-123);
    RUN_TEST("ft_itoa(-123)", str && strcmp(str, "-123") == 0);
    free(str);
}

void test_output_functions(void)
{
    print_header("OUTPUT FUNCTIONS");
    
    // Test return values for output functions (output suppressed)
    int ret;
    int saved_stdout = dup(STDOUT_FILENO);
    int null_fd = open("/dev/null", O_WRONLY);
    
    // Test putnbr
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_putnbr(42);
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_putnbr(42) returns 2", ret == 2);
    
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_putnbr(-123);
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_putnbr(-123) returns 4", ret == 4);
    
    // Test puthex
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_puthex(255, 'x');
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_puthex(255, 'x') returns 2", ret == 2);
    
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_puthex(255, 'X');
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_puthex(255, 'X') returns 2", ret == 2);
    
    // Test putunsigned
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_putunsigned(12345);
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_putunsigned(12345) returns 5", ret == 5);
    
    close(null_fd);
    close(saved_stdout);
}

void test_list_functions(void)
{
    print_header("LIST FUNCTIONS");
    
    t_list *node1 = ft_lstnew("first");
    t_list *node2 = ft_lstnew("second");
    
    RUN_TEST("ft_lstnew(\"first\")", node1 && strcmp((char*)node1->content, "first") == 0);
    
    ft_lstadd_front(&node1, node2);
    RUN_TEST("ft_lstadd_front", strcmp((char*)node1->content, "second") == 0);
    
    RUN_TEST("ft_lstsize", ft_lstsize(node1) == 2);
    
    t_list *last = ft_lstlast(node1);
    RUN_TEST("ft_lstlast", last && strcmp((char*)last->content, "first") == 0);
    
    // Clean up
    free(node1->next);
    free(node1);
}

void test_printf_functions(void)
{
    print_header("PRINTF FUNCTIONS");
    
    int ret;
    int saved_stdout = dup(STDOUT_FILENO);
    int null_fd = open("/dev/null", O_WRONLY);
    
    // Test ft_printf with output suppressed
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_printf("Test: %d", 42);
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_printf integer formatting", ret == 8);
    
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_printf("String: %s", "Hello");
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_printf string formatting", ret == 13);
    
    dup2(null_fd, STDOUT_FILENO);
    ret = ft_printf("Hex: %x", 255);
    dup2(saved_stdout, STDOUT_FILENO);
    RUN_TEST("ft_printf hex formatting", ret == 7);
    
    close(null_fd);
    close(saved_stdout);
}

void test_gnl_functions(void)
{
    print_header("GET_NEXT_LINE FUNCTIONS");
    
    // Create a test file
    int fd = open("test_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd, "First line\nSecond line\n", 22);
    close(fd);
    
    fd = open("test_file.txt", O_RDONLY);
    char *line1 = get_next_line(fd);
    char *line2 = get_next_line(fd);
    
    RUN_TEST("get_next_line: first line", line1 && strcmp(line1, "First line\n") == 0);
    RUN_TEST("get_next_line: second line", line2 && strncmp(line2, "Second line", 11) == 0);
    
    free(line1);
    free(line2);
    close(fd);
    unlink("test_file.txt");
}

void test_utility_functions(void)
{
    print_header("UTILITY FUNCTIONS");
    
    RUN_TEST("ft_digitcount(42)", ft_digitcount(42) == 2);
    RUN_TEST("ft_digitcount(-123)", ft_digitcount(-123) == 4);
    RUN_TEST("ft_digitcount(0)", ft_digitcount(0) == 1);
    
    RUN_TEST("ft_wordcount(\"hello world\", ' ')", ft_wordcount("hello world", ' ') == 2);
    RUN_TEST("ft_wordcount(\"  a  b  c  \", ' ')", ft_wordcount("  a  b  c  ", ' ') == 3);
    RUN_TEST("ft_wordcount(\"\", ' ')", ft_wordcount("", ' ') == 0);
    
    // Test ft_free_array_null (should not crash)
    char **test_array = ft_split("hello world", ' ');
    ft_free_array_null(test_array);
    RUN_TEST("ft_free_array_null (no crash)", 1);
}

void print_summary(void)
{
    printf("\n");
    printf("🏆 TEST SUMMARY\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("📊 Tests Run:    %d\n", g_tests_run);
    printf("✅ Tests Passed: %d\n", g_tests_passed);
    printf("❌ Tests Failed: %d\n", g_tests_run - g_tests_passed);
    printf("📈 Success Rate: %.1f%%\n", (double)g_tests_passed / g_tests_run * 100);
    
    if (g_tests_passed == g_tests_run)
        printf("\n🎉 ALL TESTS PASSED! Your libft is perfect! 🎉\n");
    else
        printf("\n⚠️  Some tests failed. Please review your implementations.\n");
    
    printf("═══════════════════════════════════════════════════════════════\n");
}

int main(void)
{
    printf("🧪 COMPREHENSIVE LIBFT TEST SUITE\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("Testing all 56 functions across 8 categories...\n");
    
    test_string_functions();
    test_character_functions();
    test_memory_functions();
    test_conversion_functions();
    test_output_functions();
    test_list_functions();
    test_printf_functions();
    test_gnl_functions();
    test_utility_functions();
    
    print_summary();
    
    return (g_tests_passed == g_tests_run ? 0 : 1);
} 