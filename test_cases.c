/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:42:59 by mcutura           #+#    #+#             */
/*   Updated: 2024/08/29 22:02:27 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N_SAMPLES 92

char const *g_teststr[N_SAMPLES] = {
	// Basic test cases
	"",
	"abcdefg",
	"********",
	"ALL UR BASE R BELONG 2 US\n",

	// Short strings
	"M",
	"C",
	"4",
	"2",
	"!",

	// Mixed character types
	"12345",
	"Hello123",
	"foo_bar",
	"foo123bar",
	"spaces and\ttabs",
	"new\nline",
	"\rreturn",

	// Special characters and punctuation
	"!@#$%^&*()_+",
	"`~",
	"[{]}|\\;:'\",<.>/?",
	"Hello, World!",
	"Café 😊",

	// Strings with varying case
	"CASE",
	"case",
	"CaSe",
	"cAsE",

	// Whitespace variations
	"    ",
	"\t\t",
	" \t \t ",

	// Unicode and extended ASCII characters
	"ümlaut",
	"naïve",
	"façade",
	"piñata",
	"résumé",
	"Pokémon",
	"你好", // Chinese
	"こんにちは", // Japanese
	"안녕하세요", // Korean
	"Здравствуйте", // Russian
	"😀😁😂🤣😃😄😅😆😉😊",

	// Long strings
	"This is a very long string designed to test how the function handles long input strings. It includes multiple sentences, punctuation, and even some special characters like !@#$. How will it fare?",

	// Edge cases
	"\0",
	"abc\0def",
	"foo\nbar\nbaz",
	"  \0  ",
	"\xff",

	// Strings with repetitive characters
	"aaaaa",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"ccccccccccccccccccccccccccccccccccccccccccccccccccccc",

	// Strings with escape sequences
	"\n",
	"\t",
	"\\",
	"\"",
	"\'",

	// Paths and URLs
	"/etc/passwd",
	"C:\\Program Files\\IBlameMS\\ ",
	"https://wow.transcend42.online",
	"ftp://transcend42.online/.env",

	// Palindromes
	"madam",
	"racecar",
	"A man a plan a canal Panama",

	// Substrings of varying complexity
	"a",
	"ab",
	"abc",
	"abcd",
	"abcde",
	"abcdef",
	"abcdefg",
	"abcdefgh",
	"abcdefghi",
	"abcdefghij",

	// 'Realistic' text samples
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
	"The quick brown fox jumps over the lazy dog",
	"In a hole in the ground there lived a hobbit.",

	// Numeric strings
	"1234567890",
	"-9876543210",
	"3.14159",
	"-42",
	"0xDEADBEEF",
	"2.99792458e8",

	// Boolean strings
	"true",
	"false",

	// Strings with control characters
	"\x01\x02\x03\x04\x05",

	// Random strings of various lengths
	"qxJ9e",
	"a3$d%f^G&*k",
	"jOq3P", 
	"83jdLkfdso$@jfe8",
	"Zmv1*#Sjkf3@Rfj9!2#",
	"wERoOie(23@##$5pQw",

	// Strings with different types of whitespace
	" \n\t ",
	"\v\f\r",
	"    a    b    c    ",
	" \nabc\t ", 
};
