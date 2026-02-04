/* Decompiled from: test.exe */

/* test_init @ 00100000 */
/* initializes test system */
void test_init(void) {
  global_state = 0;
}

/* test_process @ 00100020 */
/* processes test data */
int test_process(int x) {
  return x * 2;
}

/* test_cleanup @ 00100040 */
/* cleans up test resources */
void test_cleanup(void) {
  global_state = -1;
}
