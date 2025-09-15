#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - compute length of a string
 * @s: string pointer
 * Return: number of characters (0 if s is NULL)
 */
static int _strlen(char *s)
{
	int len = 0;

	while (s && s[len])
		len++;
	return (len);
}

/**
 * _strcpy - copy string from src to dest
 * @dest: destination buffer
 * @src: source string
 * Return: dest
 */
static char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name string (will be copied)
 * @age: age value
 * @owner: owner string (will be copied)
 *
 * Return: pointer to newly allocated dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int ln, lo;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	ln = _strlen(name);
	lo = _strlen(owner);

	d->name = malloc(sizeof(char) * (ln + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(sizeof(char) * (lo + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return (d);
}
