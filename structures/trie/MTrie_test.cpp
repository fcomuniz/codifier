#include <gtest/gtest.h>
#include "MTrie.h"

TEST(test_trie,test1){
	Trie t;
	t.insert("abc");
	ASSERT_TRUE(t.search("abc"));
	ASSERT_FALSE(t.search("ab"));
	t.insert("abc");
	t.insert("abdert");
	ASSERT_TRUE(t.search("abdert"));
	ASSERT_TRUE(t.startsWith("ab"));
	ASSERT_TRUE(t.startsWith("abc"));
	ASSERT_FALSE(t.startsWith("abderta"));

}
