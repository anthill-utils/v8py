V8Py
====

Write Python APIs, then call them from JavaScript using the V8 engine.

.. code-block:: python

    >>> from v8py import Context
    >>> context = Context()

    >>> def print_hello():
    ...     print 'Hello, world!'
    >>> context.expose(print_hello)
    >>> context.eval('print_hello()')
    Hello, world!

    >>> class Greeter(object):
    ...     def greet(self, thing):
    ...         print 'Welcome, {}!'.format(thing)
    >>> context.expose(Greeter)
    >>> context.eval('g = new Greeter()')
    >>> context.eval('g.greet("V8Py")')
    Welcome, V8Py!

That kind of thing.

Almost everything you'd expect to work just works, including:

* Functions
* Classes (including old style classes, because I can)
* Inheritance (from the last base class, other base classes are treated as mixins)
* Data descriptors
* Static methods and class methods
* Exceptions (they even subclass from Error!)
* `Fully meme-compliant <https://github.com/tbodt/v8py/blob/master/v8py/kappa.h>`_

Installation
------------

.. code-block:: bash

    $ pip install -i https://cdn.anthillplatform.org/python v8py

The following versions are prebuilt (x64 only):

* Windows: python 3.5+ (3.4 or older won't compile)
* Mac Os X (10.13): python 3.4+
* Linux: python 3.4+

For other python versions consider building from source.

Misc
----

There is no documentation of any of this yet. No docstrings. The best place to
look to find out how to use it is the tests.

I'm writing this so I can create a really lightweight special-purpose webdriver
(no visual rendering, no asynchronous XHRs), and I need some way of
implementing the DOM in Python. So there will definitely be enough
functionality for that. 

If you'd like to use it for something else, by all means go ahead, but you may
find something that doesn't quite "just work", or works kind of strangely, or
just stuff I forgot to test. If you find anything, please submit an issue. Or,
even better, send a pull request.

Last but not least, don't forget to

.. image:: https://img.shields.io/badge/Say%20Thanks-!-1EAEDB.svg 
   :target: https://saythanks.io/to/tbodt
