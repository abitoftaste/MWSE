
xFileWriteFloat
========================================================

**Parameters:**

- ``string`` **filename**: The file to write value to.
- ``float`` **value**: The value to write to file.

**Returned:**

- *None*

Writes a ``float`` (4 byte) **value** to **filename** at the current position. The current position is then advanced.

.. note:: The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.
