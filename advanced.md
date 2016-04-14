---
layout: post
title: Advanced Course
---

The slides for the **advanced** C course can be found here:

{% for slide in site.data.advanced.slides %}
[{{ slide.number }}. {{ slide.name }}]({{ slide.url }}){:target="_blank"}
{% endfor %}
