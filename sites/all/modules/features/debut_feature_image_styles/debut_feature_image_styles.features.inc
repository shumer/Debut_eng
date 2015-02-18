<?php
/**
 * @file
 * debut_feature_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function debut_feature_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: debut_person_alphabet_page.
  $styles['debut_person_alphabet_page'] = array(
    'name' => 'debut_person_alphabet_page',
    'label' => 'debut_person_alphabet_page',
    'effects' => array(
      9 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: debut_person_alphabet_page_mobile.
  $styles['debut_person_alphabet_page_mobile'] = array(
    'name' => 'debut_person_alphabet_page_mobile',
    'label' => 'debut_person_alphabet_page_mobile',
    'effects' => array(
      10 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: debut_person_page_photo.
  $styles['debut_person_page_photo'] = array(
    'name' => 'debut_person_page_photo',
    'label' => 'debut_person_page_photo',
    'effects' => array(
      8 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: debut_person_page_photo_mobile.
  $styles['debut_person_page_photo_mobile'] = array(
    'name' => 'debut_person_page_photo_mobile',
    'label' => 'debut_person_page_photo_mobile',
    'effects' => array(
      7 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_book_image__full.
  $styles['node__field_book_image__full'] = array(
    'name' => 'node__field_book_image__full',
    'label' => 'node__field_book_image__full',
    'effects' => array(
      6 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 190,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_book_image__home_page.
  $styles['node__field_book_image__home_page'] = array(
    'name' => 'node__field_book_image__home_page',
    'label' => 'node__field_book_image__home_page',
    'effects' => array(
      3 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 137,
          'height' => 221,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_book_image__listing.
  $styles['node__field_book_image__listing'] = array(
    'name' => 'node__field_book_image__listing',
    'label' => 'node__field_book_image__listing',
    'effects' => array(
      7 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 140,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_book_image__popup.
  $styles['node__field_book_image__popup'] = array(
    'name' => 'node__field_book_image__popup',
    'label' => 'node__field_book_image__popup',
    'effects' => array(
      4 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 229,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_jury_image__block.
  $styles['node__field_jury_image__block'] = array(
    'name' => 'node__field_jury_image__block',
    'label' => 'node__field_jury_image__block',
    'effects' => array(
      2 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 148,
          'height' => 148,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_jury_image__frame.
  $styles['node__field_jury_image__frame'] = array(
    'name' => 'node__field_jury_image__frame',
    'label' => 'node__field_jury_image__frame',
    'effects' => array(
      4 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_person_image__block.
  $styles['node__field_person_image__block'] = array(
    'name' => 'node__field_person_image__block',
    'label' => 'node__field_person_image__block',
    'effects' => array(
      1 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 148,
          'height' => 148,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_person_image__frame.
  $styles['node__field_person_image__frame'] = array(
    'name' => 'node__field_person_image__frame',
    'label' => 'node__field_person_image__frame',
    'effects' => array(
      5 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_photo_listing_photo__full.
  $styles['node__field_photo_listing_photo__full'] = array(
    'name' => 'node__field_photo_listing_photo__full',
    'label' => 'node__field_photo_listing_photo__full',
    'effects' => array(
      6 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 265,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_photo_listing_photo__listing.
  $styles['node__field_photo_listing_photo__listing'] = array(
    'name' => 'node__field_photo_listing_photo__listing',
    'label' => 'node__field_photo_listing_photo__listing',
    'effects' => array(
      3 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 314,
          'height' => 166,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_photo_listing_photo__search.
  $styles['node__field_photo_listing_photo__search'] = array(
    'name' => 'node__field_photo_listing_photo__search',
    'label' => 'node__field_photo_listing_photo__search',
    'effects' => array(
      1 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 366,
          'height' => 144,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_video_image__home_page.
  $styles['node__field_video_image__home_page'] = array(
    'name' => 'node__field_video_image__home_page',
    'label' => 'node__field_video_image__home_page',
    'effects' => array(
      5 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 211,
          'height' => 123,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
