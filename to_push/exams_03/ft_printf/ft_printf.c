int ft_putstr ()

int	ft_printf(cnst char *format)
{
	int len;
	va_list args;
	va_start(args, format);

	len = 0;
	while (*format)
	{
		if (*format == '%' && (((*format + 1) == 's') || ((*format + 1) == 'd') || ((*format + 1) == 'c')) || ((*format + 1) == 'x'))
		{
			if ((*format + 1) == 's')
				len += ft_putstr(va_arg(args, char *));
			else if ((*format + 1) == 'd')
				len += ft_putnbr(va_arg(args, int));
			else if ((*format + 1) == 'c')
				len += ft_putchar(va_arg(args, int));
			else if ((*format + 1) == 'x')
				len += ft_puthex(va_arg(args, int));
			format += 2;
		}
		else
		{
			ft_putchar(*format);
			format++;
			len++;
		}
	}
	return (len);
}
