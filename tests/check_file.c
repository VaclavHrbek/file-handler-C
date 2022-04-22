#include <stdlib.h>
#include <check.h>
#include "../include/file.h"

START_TEST(test_file_create){
	// normal name test 
	const char* file_name = "test-file";
	ck_assert_ptr_nonnull(create_file(file_name));
	// no name test (fail)
	file_name = "";
	ck_assert_ptr_null(create_file(file_name));
}
END_TEST

START_TEST(test_file_delete){
	// normal name test 
	const char* file_name = "test-file";
	ck_assert_ptr_null(delete_file(file_name));
	// no name test (fail)
	file_name = "";
	ck_assert_ptr_nonnull(delete_file(file_name));
}
END_TEST

START_TEST(test_add_line_to_file){
	// normal name test 
	const char* file_name = "test-file";
	char* line_to_add = "This is test line from add unit test";
	create_file(file_name);
	add_line_to_file(file_name, line_to_add);
	char* res = read_last_line_from_file(file_name);
	ck_assert_str_eq(res, line_to_add);
	free(res);
	delete_file(file_name);
}
END_TEST

START_TEST(test_read_last_line){
	// normal name test 
	const char* file_name = "test-file";
	char* line_to_read_1 = "This is first test line from unit test";
	char* line_to_read_2 = "This is second test line from unit test";
	char* line_to_read_3 = "This is third test line from unit test";
	create_file(file_name);
	add_line_to_file(file_name, line_to_read_1);
	add_line_to_file(file_name, line_to_read_2);
	add_line_to_file(file_name, line_to_read_3);
	char* res = read_last_line_from_file(file_name);
	ck_assert_str_eq(res, line_to_read_3);
	free(res);
	delete_file(file_name);
}
END_TEST
 
Suite* file_suite(void){
	Suite* s;
	TCase* tc;

	s = suite_create("FILE");
	tc = tcase_create("CORE");
	tcase_add_test(tc, test_file_create);
	tcase_add_test(tc, test_file_delete);
	tcase_add_test(tc, test_add_line_to_file);
	tcase_add_test(tc, test_read_last_line);
	suite_add_tcase(s, tc);
	return s;
}

int main(void){
	int number_failed;
	Suite* s;
	SRunner *sr;

	s = file_suite();
	sr = srunner_create(s);
	srunner_set_fork_status (sr, CK_NOFORK);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
